#include <vector>
#include <cstring>
#include <memory>
#include <map>
#include <string>
#include <iostream>

class IProcess {
public:
    virtual void execute() = 0;
    virtual std::string getName() const = 0;
    virtual int getPid() const = 0;
    virtual std::vector<uint8_t> serialize() const = 0;
    virtual void clear() = 0;
    virtual void deserialize(const std::vector<uint8_t>& data) = 0;
    virtual std::string getProcessType() const = 0;
    virtual ~IProcess() = default;
};

class ProcessState {
private:
    std::vector<uint8_t> rawData;
    std::string processType;

public:
    void saveProcess(IProcess* process) {
        rawData = process->serialize();
        processType = process->getProcessType();
        process->clear();
    }

    bool restoreProcess(IProcess* process) const {
        if (process->getProcessType() != processType){
            return false;
        }
        process->deserialize(rawData);
        return true;
    }

    std::string getProcessType() const { return processType; }
};

class SimpleProcess : public IProcess {
private:
    struct Context {
        int pid;
        char name[64];
        int programCounter;
        int accumulator;
    };

    Context ctx;

public:
    SimpleProcess(int pid, const std::string& name) {
        ctx.pid = pid;
        strncpy(ctx.name, name.c_str(), sizeof(ctx.name) - 1);
        ctx.programCounter = 0;
        ctx.accumulator = 0;
    }

    void execute() override {
        ctx.programCounter++;
        ctx.accumulator += ctx.programCounter;
        std::cout << "[Simple Process] programCounter: " << ctx.programCounter << ", accumulator: " << ctx.accumulator << std::endl;
    }

    std::string getName() const override {
        return ctx.name;
    }

    int getPid() const override {
        return ctx.pid;
    }

    std::string getProcessType() const override {
        return "SimpleProcess";
    }

    std::vector<uint8_t> serialize() const override {
        std::vector<uint8_t> data(sizeof(Context));
        memcpy(data.data(), &ctx, sizeof(Context));
        return data;
    }

    void clear() override {
        ctx.programCounter = 0;
        ctx.accumulator = 0;
    }

    void deserialize(const std::vector<uint8_t>& data) override {
        memcpy(&ctx, data.data(), sizeof(Context));
    }
};

class ComplexProcess : public IProcess {
private:
    struct Header {
        int pid;
        char name[64];
        int vectorSize;
    };

    int pid;
    std::string name;
    std::vector<int> data;

public:
    ComplexProcess(int pid, const std::string& name) 
        : pid(pid), name(name) {}

    void execute() override {
        data.push_back(data.size());
        std::cout << "[Complex Process] data.size(): " << data.size() << std::endl;
    }

    std::string getName() const override { return name; }
    int getPid() const override { return pid; }
    
    std::string getProcessType() const override {
        return "ComplexProcess";
    }

    std::vector<uint8_t> serialize() const override {
        Header header;
        header.pid = pid;
        strncpy(header.name, name.c_str(), sizeof(header.name) - 1);
        header.vectorSize = data.size();

        std::vector<uint8_t> result(sizeof(Header) + data.size() * sizeof(int));
        std::memcpy(result.data(), &header, sizeof(Header));
        
        if (!data.empty()) {
            std::memcpy(result.data() + sizeof(Header), 
                       data.data(), 
                       data.size() * sizeof(int));
        }

        return result;
    }

    void clear() override {
        data.clear();
    }

    void deserialize(const std::vector<uint8_t>& raw) override {
        if (raw.size() < sizeof(Header)) return;

        Header header;
        std::memcpy(&header, raw.data(), sizeof(Header));

        pid = header.pid;
        name = header.name;

        data.resize(header.vectorSize);
        if (header.vectorSize > 0) {
            std::memcpy(data.data(), 
                       raw.data() +sizeof(Header), 
                       header.vectorSize * sizeof(int));
        }
    }
};

class Scheduler {
private:
    int timeQuantum = 3;
    std::map<int, std::shared_ptr<IProcess>> processes;
    std::map<int, ProcessState> processStates;
    int currentPid = -1;
    int currentTimeSlice = 0;
    bool isRunning = false;

    void saveCurrent() {
        if (currentPid != -1) {
            auto it = processes.find(currentPid);
            if (it != processes.end()) {
                processStates[it->first].saveProcess(it->second.get());
                std::cout << "Saved process " << currentPid << "\n";
            }
        }
    }

    void scheduleNext() {
        if (processes.empty()) return;

        if (currentTimeSlice >= timeQuantum) {
            saveCurrent();
            currentTimeSlice = 0;
        } else if (currentPid != -1) {
            return;
        }

        auto it = processes.upper_bound(currentPid);
        if (it == processes.end()) {
            it = processes.begin();
        }
        currentPid = it->first;

        /*
            Task 7 - do something with it 
        */
        processStates[currentPid].restoreProcess(it->second.get());

        std::cout << "Started process " << currentPid << "\n";
    }

public:
    Scheduler(int quantum = 3) : timeQuantum(quantum) {}

    void addProcess(std::shared_ptr<IProcess> process) {
        processes[process->getPid()] = process;
        std::cout << "Added process " << process->getPid() << "\n";
    }

    void removeProcess(int pid) {
        processes.erase(pid);
        processStates.erase(pid);
        if (currentPid == pid) {
            currentPid = -1;
            currentTimeSlice = 0;
        }
    }

    void tick() {
        if (!isRunning) {
            return;
        }
        scheduleNext();
        processes[currentPid]->execute();
        currentTimeSlice++;
        
        std::cout << "Process " << currentPid 
                    << " executed (tick " << currentTimeSlice 
                    << " of " << timeQuantum << ")\n";
    }

    void start() {
        isRunning = true;
        std::cout << "Scheduler started\n";
    }

    void stop() {
        isRunning = false;
        saveCurrent();
        std::cout << "Scheduler stopped\n";
    }

    int getCurrentPid() const {
        return currentPid;
    }

    void setTimeQuantum(int quantum) {
        timeQuantum = quantum;
    }
};


int main() {
    Scheduler scheduler(3);

    auto simpleProc = std::make_shared<SimpleProcess>(1, "Simple");
    auto complexProc = std::make_shared<ComplexProcess>(2, "Complex");

    scheduler.addProcess(simpleProc);
    scheduler.addProcess(complexProc);
    
    scheduler.start();

    for (int i = 0; i < 20; ++i) {
        std::cout << "\n=== Tick " << i << " ===\n";
        scheduler.tick();
    }

    scheduler.stop();

    return 0;
}

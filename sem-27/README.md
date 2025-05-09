nc localhost 8080

sudo tcpdump -i lo port 8080 -nn -v

| Number of file descriptors  | poll() CPU time | select() CPU time | epoll() CPU time |
| ------------- | ------------- | ------------- | ------------- | 
| 10  | 0.61  | 0.73 | 0.41 |
| 100  | 2.9  | 3 | 0.42 |
| 1000  | 35  | 35 | 0.53 |
| 10000  | 990  | 930 | 0.66 |

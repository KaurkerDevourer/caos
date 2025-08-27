package heavy

type HeavyObject struct {
	ID    int
	Data  [1024]byte // Большой массив для имитации "тяжелого" объекта
	Value float64
}

func FillObjects2(objects []interface{}) []interface{} {
	for i := 0; i < len(objects); i++ {
		objects[i].(*HeavyObject).ID = i
		objects[i].(*HeavyObject).Value = float64(i) * 3.14
	}
	return objects
}

func FillObjects(objects []interface{}) []interface{} {
	for i := 0; i < len(objects); i++ {
		obj := HeavyObject{
			ID:    i,
			Value: float64(i) * 3.14,
		}
		objects[i] = obj
	}
	return objects
}

func Create(n int) []interface{} {
	objects := make([]interface{}, n)
	objects = FillObjects(objects)
	return objects
}

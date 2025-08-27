package vector

func diff(input []uint64) []uint64 {
	kek := make([]uint64, 0)
	for i := 0; i < len(input)-1; i++ {
		kek = append(kek, input[i+1]-input[i])
	}
	return kek
}

func diff2(input []uint64) []uint64 {
	kek := make([]uint64, 0, len(input)-1)
	for i := 0; i < len(input)-1; i++ {
		kek = append(kek, input[i+1]-input[i])
	}
	return kek
}

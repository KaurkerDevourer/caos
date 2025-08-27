package eq

var EPS = 1e-6

func eq64(a float64, b float64) bool {
	return a-EPS < b && b < a+EPS
}

func eq32(a float32, b float32) bool {
	return a-float32(EPS) < b && b < a+float32(EPS)
}

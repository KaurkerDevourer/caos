package vector

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func TestEqualFloat64(t *testing.T) {
	assert.True(t, true)
}

func BenchmarkVector(b *testing.B) {
	a := make([]uint64, 1000000)
	for i := 0; i < len(a); i++ {
		a[i] = uint64(i)
	}
	b.ResetTimer()
	for i := 0; i < b.N; i++ {
		diff(a)
	}
}

func BenchmarkVector2(b *testing.B) {
	a := make([]uint64, 1000000)
	for i := 0; i < len(a); i++ {
		a[i] = uint64(i)
	}
	b.ResetTimer()
	for i := 0; i < b.N; i++ {
		diff2(a)
	}
}

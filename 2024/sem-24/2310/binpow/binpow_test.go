package binpow

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func TestEqualFloat64(t *testing.T) {
	assert.Equal(t, uint64(8), binpow(2, 3, 10))
}

func BenchmarkBinpow(b *testing.B) {
	b.ResetTimer()
	b.StopTimer()
	b.StartTimer()
	for i := 0; i < b.N; i++ {
		binpow(2, 1000000, 1000000007)
	}
}

func BenchmarkBinpowFixed(b *testing.B) {
	b.ResetTimer()
	b.StopTimer()
	b.StartTimer()
	for i := 0; i < b.N; i++ {
		binpow_fixed(2, 1000000, 1000000007)
	}
}

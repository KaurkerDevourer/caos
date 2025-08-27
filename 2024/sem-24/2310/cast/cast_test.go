package cast

import (
	"testing"
)

func BenchmarkCast(b *testing.B) {
	for i := 0; i < b.N; i++ {
		num := cast("abc")
		_ = num
	}
}

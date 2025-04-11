package heavy

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func TestEqualFloat64(t *testing.T) {
	assert.True(t, true)
}

func BenchmarkCreate(b *testing.B) {
	objects := make([]interface{}, 10000)
	b.ResetTimer()
	for i := 0; i < b.N; i++ {
		FillObjects(objects)
	}
}

func BenchmarkCreate2(b *testing.B) {
	objects := make([]interface{}, 10000)
	for i := 0; i < len(objects); i++ {
		objects[i] = &HeavyObject{}
	}
	b.ResetTimer()
	for i := 0; i < b.N; i++ {
		FillObjects2(objects)
	}
}

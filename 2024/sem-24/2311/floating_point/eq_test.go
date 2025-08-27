package eq

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func TestEqualFloat64(t *testing.T) {
	a := 0.1
	b := 0.2
	assert.True(t, eq64(a+b, 0.3))
}

func TestEqualFloat32(t *testing.T) {
	a := float32(2.6)
	b := float32(0.1)
	assert.True(t, eq32(a+b, 2.7))
}

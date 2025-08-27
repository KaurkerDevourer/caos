package calc

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func TestCalculate(t *testing.T) {
	assert.Equal(t, int64(1), Calculate(1, 9223372036854775807))
	assert.Equal(t, int64(-1), Calculate(9223372036854775807, 1))
}

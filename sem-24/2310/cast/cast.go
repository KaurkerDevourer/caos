package cast

import "strconv"

func cast(s string) int64 {
	i, _ := strconv.ParseInt(s, 10, 64)
	return i
}

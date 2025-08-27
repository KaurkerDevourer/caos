package binpow

func binpow(a uint64, n uint64, mod uint64) uint64 {
	if n == 0 {
		return 1
	}
	if n%2 == 0 {
		return (binpow(a, n/2, mod) * binpow(a, n/2, mod)) % mod
	} else {
		return (binpow(a, n-1, mod) * a) % mod
	}
}

func binpow_fixed(a uint64, n uint64, mod uint64) uint64 {
	if n == 0 {
		return 1
	}
	if n%2 == 0 {
		b := binpow_fixed(a, n/2, mod)
		return (b * b) % mod
	} else {
		return (binpow_fixed(a, n-1, mod) * a) % mod
	}
}

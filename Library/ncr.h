#require MOD
template<class T> struct nCk {
	vector<T> fact_, inv_, finv_;
	constexpr nCk() {}
	constexpr nCk(int n) noexcept : fact_(n, 1), inv_(n, 1), finv_(n, 1) {
		init(n);
	}
	constexpr void init(int n) noexcept {
		fact_.assign(n, 1), inv_.assign(n, 1), finv_.assign(n, 1);
		for (int i = 2; i < n; i++) {
			fact_[i] = fact_[i - 1] * i;
			inv_[i] = -inv_[MOD%i] * (MOD / i);
			finv_[i] = finv_[i - 1] * inv_[i];
		}
	}
	constexpr T nCr(int n, int k) const noexcept {
		if (n < k || n < 0 || k < 0) return 0;
		return fact_[n] * finv_[k] * finv_[n - k];
	}
	constexpr T fact(int n) const noexcept {
		if (n < 0) return 0;
		return fact_[n];
	}
	constexpr T inv(int n) const noexcept {
		if (n < 0) return 0;
		return inv_[n];
	}
	constexpr T finv(int n) const noexcept {
		if (n < 0) return 0;
		return finv_[n];
	}
};

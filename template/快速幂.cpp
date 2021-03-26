// https://blog.csdn.net/qq_19782019/article/details/85621386
ll quickPower1(ll base, ll power) {
    ll mod = 1e7;
    ll res = 1;
    while (power > 0) {
        if (power % 2 == 0) {
            power /= 2;
            base = base * base % mod;
        } else {
            power -= 1;
            res = res * base % mod;
            power /= 2;
            base = base * base % mod;
        }
    }
    return res;
}

ll quickPower2(ll base, ll power) {
    ll mod = 1e7;
    ll res = 1;
    while (power > 0) {
        if (power & 1) {
            res = res * base % mod;
        }
        power >>= 1;
        base = base * base % mod;
    }
    return res;
}

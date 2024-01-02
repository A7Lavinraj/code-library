#include <bits/stdc++.h>
using namespace std;

struct sieve {
  vector<bool> prime;
  sieve(size_t N = 100) {
    prime.assign(N + 1, true);

    prime[0] = prime[1] = false;
    for (int i = 2; i <= N; i++) {
      for (int j = 2; i * j <= N; j++) {
        prime[i * j] = false;
      }
    }
  }

  vector<int> primes() {
    vector<int> result;
    for (int i = 2; i <= int(prime.size()); i++) {
      if (prime[i]) result.push_back(i);
    }

    return result;
  }

  bool is_prime(int n) {
    return prime[n];
  }

} primes(1000);

int main() {
  return 0;
}


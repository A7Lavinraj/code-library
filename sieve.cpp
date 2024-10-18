#include <vector>

const int N = int(100);
std::vector<bool> is_prime;
std::vector<int> primes;

void sieve() {
  is_prime.assign(N + 1, true);

  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i <= N; i++) {
    for (int j = 2; i * j <= N; j++) {
      is_prime[i * j] = false;
    }
  }

  for (int i = 2; i <= N; i++)
    if (is_prime[i] == true)
      primes.push_back(i);
}

def tokenize(n, m, dictionary, tokens):
    full_string = "".join(tokens)

    word_set = set(dictionary)

    memo = {}

    def backtrack(start):
        if start == len(full_string):
            return []

        if start in memo:
            return memo[start]

        for end in range(start + 1, len(full_string) + 1):
            word = full_string[start:end]
            if word in word_set:
                result = backtrack(end)
                if result is not None:
                    memo[start] = [word] + result
                    return memo[start]

        memo[start] = None
        return None

    result = backtrack(0)

    if result:
        print(" ".join(result))
    else:
        print(-1)

def main():
    n, m = map(int, input().split())
    dictionary = [input().strip() for _ in range(m)]
    tokens = input().split()

    tokenize(n, m, dictionary, tokens)

if __name__ == "__main__":
    main()

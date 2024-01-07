function createCounter(n: number): () => number {
    let count: number = n;
    return function() {
        return count++
    }
}
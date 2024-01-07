type Fn = (...params: number[]) => number

function memoize(fn: Fn): Fn {
    let cache = {};

    return function(...args) {
        const id = JSON.stringify(args);

        if (id in cache) return cache[id]

        const calcValue: number = fn(...args);
        cache[id] = calcValue;
        return calcValue
    }
}
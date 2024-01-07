type ReturnObj = {
    increment: () => number,
    decrement: () => number,
    reset: () => number,
}

function createCounter(init: number): ReturnObj {
    let count: number = init;

    return {
        increment: function() {
            return ++count
        },
        decrement: function() {
            return --count
        },
        reset: function() {
            return count = init
        },
    }
};
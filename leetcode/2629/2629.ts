type F = (x: number) => number;

function compose(functions: F[]): F {
    return function(x) {
        let res: number = x;
        functions.reverse().forEach(func => {
            res = func(res)
        })

        return res
    }
};
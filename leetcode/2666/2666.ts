type JSONValue = null | boolean | number | string | JSONValue[] | { [key: string]: JSONValue };
type OnceFn = (...args: JSONValue[]) => JSONValue | undefined

function once(fn: Function): OnceFn {
    let cache: any = null;

    return function (...args) {
        if (cache !== null) return undefined

        const calcValue: number = fn(...args);
        cache = calcValue;
        return calcValue
    };
}
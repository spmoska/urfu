type JSONValue = null | boolean | number | string | JSONValue[] | { [key: string]: JSONValue };

declare global {
    interface Function {
        callPolyfill(context: Record<string, JSONValue>, ...args: JSONValue[]): JSONValue;
    }
}

Function.prototype.callPolyfill = function(context, ...args): JSONValue {
    return this.bind(context)(...args)
}
type JSONValue = null | boolean | number | string | JSONValue[] | { [key: string]: JSONValue };
type Obj = Record<string, JSONValue> | Array<JSONValue>;

function chunk(arr: Obj[], size: number): Obj[][] {
    let chunkedArray: Obj[][] = [];
    let startIndex: number = 0;
    let endIndex: number = size;
    while (startIndex < arr.length ) {
        let chunk: Obj[] = arr.slice(startIndex, endIndex);
        chunkedArray.push(chunk);
        startIndex += size;
        endIndex += size;
    }

    return chunkedArray
};
type MultiDimensionalArray = (number | MultiDimensionalArray)[];

var flat = function (arr:  MultiDimensionalArray, n: number):  MultiDimensionalArray {
    const res: MultiDimensionalArray = [];

    function getFlat(arr: number | MultiDimensionalArray, n: number) {
        if (typeof arr === 'number') {
            res.push(arr);
        } else if (n === 0) {
            for (const element of arr) {
                res.push(element);
            }
        } else {
            for (const element of arr) {
                getFlat(element, n - 1);
            }
        }
    }

    getFlat(arr, n);
    return res;
};
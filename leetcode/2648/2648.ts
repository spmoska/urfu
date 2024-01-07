function* fibGenerator(): Generator<number, any, number> {
    let currentNumber = 0;
    let nextNumber = 1;

    while (true) {
        yield currentNumber;
        [currentNumber, nextNumber] = [nextNumber, currentNumber + nextNumber];
    }
};
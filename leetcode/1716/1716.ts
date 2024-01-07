function totalMoney(n: number): number {
    let res: number = 0;
    let dailyMoney: number = 1;
    let startMoney: number = 1;
    [...Array(n).keys()].forEach((index: number) => {
        if (index % 7 === 0 && index !== 0) {
            startMoney++;
            dailyMoney = startMoney;
        }
        res += dailyMoney;
        dailyMoney++;
    })

    return res
};
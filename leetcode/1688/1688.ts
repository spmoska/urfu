function numberOfMatches(teams: number): number {
    let matches: number = 0;

    while (teams !== 1) {
        if (teams % 2 === 0) {
            matches += teams / 2;
            teams /= 2;
        } else {
            matches += (teams - 1) / 2;
            teams = (teams - 1) / 2 + 1;
        }
    }

    return matches
}

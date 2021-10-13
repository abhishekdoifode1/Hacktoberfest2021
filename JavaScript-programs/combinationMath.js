function* combinations(iterable, n, withReplacement = false) {
  const array = [...iterable];
  if (n === 1) {
    yield* array.map(i => [i]);
    return;
  }
  for (const [item, index] of enumerate(array)) {
    const withoutCurrent = withReplacement ? array : array.slice(index + 1);
    for (const combination of combinations(withoutCurrent, n - 1, withReplacement)) {
      yield [item, ...combination];
    }
  }
}

function* enumerate(iterable) {
  let index = 0;
  for (const item of iterable) {
    yield [item, index];
    index++;
  }
}

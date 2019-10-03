function countVocal(string) {
	let aieou = 'aeiouAEIOU';
	let result = 0;

	for (let i = 0; i < string.length; i++) {
		if (aieou.indexOf(string[i]) !== -1) {
			result++
		}
	}
	console.log(result)
}

countVocal('hacktober')
countVocal('mhdrare')

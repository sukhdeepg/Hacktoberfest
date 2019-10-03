//penerapan map huruf menjadi kecil semua
let arr0 = ['BUDI', 'MArNi', 'mukIDi'];
let transformArrToLowerCase = arr0.map(isiarray => {
  // Ubah setiap element array menjadi lowercase!
  return isiarray.toLowerCase();
});
console.log("PENERAPAN MAP LOWER CASE");
console.log(transformArrToLowerCase); // ['budi', 'marni', 'mukidi']
console.log("*************************************");

//melakukan filter angka pada array
let arr1 = [1, 5, 12, 15, 20];
let filterArrUnder10 = arr1.filter(isiarray => {
  // Filter setiap element array yang nilainya dibawah 10, sisakan yang 10 ke atas!
  return isiarray > 10;
});

console.log("PENERAPAN FILTER ANGKA");
console.log(filterArrUnder10); // [12, 15, 20]
console.log("*************************************");

//pencarian nilai terbesar dalam array
var arr2 = [5, 1, 7, 6, 9, 20, 3, 40];
var reduceFindMaximum = arr2.reduce((nilai1, nilai2) => {
  return nilai2 > nilai1 ? nilai2 : nilai1;
});
console.log("PENCARIAN NILAI TERBESAR DALAM ARRAY");
console.log(reduceFindMaximum); // 9
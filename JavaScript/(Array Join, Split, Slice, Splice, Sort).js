function dataHandling2(input) {
  input.splice(1, 2, 'Roman Alamsyah Elsharawy', 'Propinsi Bandar Lampung')
  input.splice(4, 2, 'Pria', 'SMA Internasional Metro')
  console.log(input)
  var tanggalBulanTahun = input[3].split('/');
  var bulan = Number(tanggalBulanTahun[1]);
  switch (bulan) {
    case 1:
      console.log("Januari");
      break;
    case 2:
      console.log("Febuari");
      break;
    case 3:
      console.log("Maret");
      break;
    case 4:
      console.log("April");
      break;
    case 5:
      console.log("Mei");
      break;
    case 6:
      console.log("Juni");
      break;
    case 7:
      console.log("Juli");
      break;
    case 8:
      console.log("Agustus");
      break
    case 9:
      console.log("September");
      break;
    case 10:
      console.log("November");
      break
    case 11:
      console.log("Oktober");
      break;
    case 12:
      console.log("Desember");
      break;
  }
  var elemetJoin = tanggalBulanTahun.join('-');

  var sorting = tanggalBulanTahun.sort(function (a, b) {
    return b - a
  })
  console.log(sorting)

  console.log(elemetJoin)

  input.splice(1, 1, 'Roman Alamsyah')
  console.log(input[1])

}

var input = ["0001", "Roman Alamsyah", "Bandar Lampung", "21/05/1989", "Membaca"];
console.log(dataHandling2(input));
function addCommas(num) {
    num += '';
    var n1 = num.split('.');
    var n2 = n1[0];
    var n3 = n1.length > 1 ? '.' + n1[1] : '';
    var temp = /(d+)(d{3})/;
    while (temp.test(n2)) {
      n2 = n2.replace(temp, '' + ',' + '');
    }
    var out =  n2 + n3;
    document.write(out);
  }

  addCommas("4550989023");
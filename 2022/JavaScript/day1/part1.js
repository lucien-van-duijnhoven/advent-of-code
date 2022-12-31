// read file from input.txt from ../../inputs/day1/full.txt. Then split the file from likes to array of strings.

const fs = require('fs');
const path = require('path');

const input = fs.readFileSync(path.join(__dirname, '../../inputs/day1/full.txt'), 'utf8').split('\r\n');

let elfs = [[]];
let elf = [];

for (line of input) {
    if (line == '') {
        if (elf.length > 0) {
            elfs.push(elf);
        }
        elf = [];
    } else {
        elf.push(line);
    }
}
if (elf.length > 0) {
    elfs.push(elf);
}

const elfsSumSorted = elfs.map(elf => {
    total = 0;
    elf.forEach(number => {
        total += parseInt(number);
    });
    return total;
}).sort((a, b) => a - b);

if (elfsSumSorted.length > 0) {
    console.log("The higherst amount is: ", elfsSumSorted[elfsSumSorted.length - 1]);
} else {
    console.log("No elfs found");
}

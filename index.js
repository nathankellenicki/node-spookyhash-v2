const SpookyHashV2 = require("./build/release/spookyhash-v2");

let testBuffer = Buffer.from([0xff, 0xff, 0xf3, 0xde, 0x00, 0xe5]);

let hash1 = Buffer.from([0x0a, 0xa0, 0xee, 0xca, 0xee, 0x2a, 0x9d, 0xd0]),
    hash2 = Buffer.from([0xc2, 0xe1, 0x13, 0x2e, 0xe0, 0x0a, 0x23, 0xb1]);

console.log(testBuffer);
let hash = SpookyHashV2.hash128(testBuffer, hash1, hash2);
console.log(hash);
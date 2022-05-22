use std::io;

fn main(){
    let mut TEST_CASES: String = String::new();
    io::stdin()
        .read_line(&mut TEST_CASES)
        .expect("Couldn't read");

    let TEST_CASES: &str = TEST_CASES.trim();
    let TEST_CASES: u32 = TEST_CASES.parse().unwrap();

    for TEST_CASE in 1..TEST_CASES {
        let mut RESULT: u32 = 0;

        println!("Case #{}: {}", TEST_CASE, RESULT)
    }
}
// Baekjoon02721.swift
import Foundation

func funcW(n: Int) -> Int {
    func funcT(n: Int) -> Int {
        var result = 0
        for i in 1...n {
            result += i
        }
        return result
    }

    var ans = 0
    for k in 1...n {
        ans += k * funcT(n: k + 1)
    }

    return ans
}

let t = Int(readLine()!)!
for _ in 0..<t {
    let input = Int(readLine()!)!
    print(funcW(n: input))
}
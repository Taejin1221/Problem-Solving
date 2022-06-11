// Programmers42748.swift
import Foundation

func solution(_ array:[Int], _ commands:[[Int]]) -> [Int] {
    var ans: [Int] = []
    for command in commands {
      var cutArr: [Int] = []
      for i in command[0] - 1...command[1] - 1 {
          cutArr.append(array[i])
      }

      cutArr.sort()

      ans.append(cutArr[command[2] - 1])
    }

    return ans
}
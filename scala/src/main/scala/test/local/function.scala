package test.local

import scala.math._

class function {
    def test1(): Unit = {
        val num = 3.14
        // ceil函数后的_意味着你确实指的是这个函数，而不是碰巧忘记了给它送参数
        // _将ceil方法转成了函数，在Scala中，你无法直接操作方法，而只能直接操作函数
        val fun = ceil _
        println(fun(num))

    }

    def lamb(): Unit = {
        Array(3.14, 1.42, 2.0).map(x => {
            val a = x * 3
            println(a)
            a
        })
    }

    // 带函数参数的函数
    def valueAtOneQuarter(f: (Double) => Double) = f(0.25)

    def test2(): Unit = {
        valueAtOneQuarter(ceil _)   // 1.0
        valueAtOneQuarter(sqrt _)   // 0.5

        // 基于参数类型推断，下面四个调用的结果相同
        // 简写方式仅在参数类型已知的情况下有效。
        valueAtOneQuarter((x: Double) => 3 * x)
        valueAtOneQuarter((x) => 3 * x)
        valueAtOneQuarter(x => 3 * x)   // 如果参数在=>右侧只出现一次，可以用下面的方式
        valueAtOneQuarter(3 * _)
    }

    // 高阶函数也可以产出另一个函数，
    // mulBy函数有一个类型为Double的参数，返回的匿名函数
    // (x: Double) => factor * x 是匿名函数
    // mulBy函数的类型为：(Double) => ((Double) => Double)
    def mulBy(factor: Double) = (x: Double) => factor * x

    def test3(): Unit = {
        val quintuple = mulBy(5)    // (x: Double) => 5 * x
        quintuple(20)
    }

    def test4(): Unit = {
        // 这里有一个通用的原则，如果你要的是一个序列的值，那么想办法从一个简单的序列转化得出
        (1 to 9).map(0.1 * _)   // 0.1, 0.2, ..., 0.9

        // 打印一个三角形
        (1 to 9).map("*" * _).foreach(println(_))

    }
}

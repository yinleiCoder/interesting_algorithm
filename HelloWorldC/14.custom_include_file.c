#include <stdio.h>
//#includes "includes/factorial.h"
#include <factorial.h>
/**
 * 自定义头文件
 *
 * #includes "xx.h"
 * 1. 首先查找当前源文件所在路径
 * 2. 查找工程的头文件搜索路径
 *
 * #includes <xx.h>
 * 查找工程的头文件搜索路径
 * @return
 */
int main(void) {
  printf("3!: %d\n", Factorial(3));
  printf("3!: %d\n", FactorialByIteration(3));

  return 0;
}

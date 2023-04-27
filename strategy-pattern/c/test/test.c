#include "../src/func.h"

int main(void)
{
	printf("test start:\r\n");

	/**
	 * 策略模式就是根据需要给对象绑定具体策略，使得具体实现和策略可以灵活搭配。
	 * 先声明某个具体Context对象，该对象已经绑定了具体策略，同时还可以更改策略。
	 */

	// 声明策略执行对象
	Context *context = context_constructor("context");

	// 设置策略A
	context->set_strategy(context, (Strategy *)strategy_a_constructor("strategy_a"));

	// 执行策略A，打印StrategyA
	context->run(context);

	// 设置策略B
	context->set_strategy(context, (Strategy *)strategy_b_constructor("strategy_b"));
	// 执行策略B，打印StrategyB
	context->run(context);

	// 执行策略C，打印StrategyC
	context->set_strategy(context, (Strategy *)strategy_c_constructor("strategy_c"));
	context->run(context);

	/*********************** 分割线 ******************************************/

	// 直接实例化具体执行对象，策略已经绑定
	ContextCat *context_cat = context_cat_constructor("context_cat");
	context_cat->run(context_cat);

	// 直接实例化具体执行对象，策略已经绑定
	ContextDog *context_dog = context_dog_constructor("context_dog");
	context_dog->run(context_dog);
}

/**
jarry@jarrys-MacBook-Pro c % gcc test/test.c ./src下*.c
jarry@jarrys-MacBook-Pro c % ./a.out
test start:

 context_run() [context=context strategy=strategy_a]
 StrategyA::run()
 context_run() [context=context strategy=strategy_b]
 StrategyB::run()
 context_run() [context=context strategy=strategy_c]
 StrategyC::run()
 context_cat_constructor() [构建ContextCat]
 context_cat_run() [context=context_cat strategy=strategy_c]
 StrategyC::run()
 context_dog_constructor() [构建ContextDog]
 context_dog_run() [context=context_dog strategy=strategy_b]
 StrategyB::run()%  
 */
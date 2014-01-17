#include "bamboo.hxx"
#include <stdio.h>

using namespace bamboo;

int main(int argc, char *argv[])
{
	size_t i;

	ParserFactory* parser_fact = ParserFactory::get_instance();
	Parser* parser = parser_fact->create("crf_seg", "", true);
	parser->setopt(BAMBOO_OPTION_TEXT, argv[1]);

	std::vector<Token*> x;
	parser->parse(x);

	for(int i = 0; i < x.size(); i++)
	{
		Token* token = x[i];
		printf("%s ", token->get_orig_token());
		delete token;
	}

}

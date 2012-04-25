#include <stdio.h>
#include <stdlib.h>

typedef struct hashtable_node {
	char * data;
	struct hashtable_node * next;
}htn;

#define HL 100

htn *ht[HL];

char * strcpy(char *to, char *from)
{
	char * a = to;
	while (*to++ = *from++);
	return a;
}

int strlen(char *s)
{
	char *p = s;
	while (*p)
		p++;
	return p - s;
}

int strcmp(char *a, char *b)
{
	while (*a == *b) {
		if (*a == '\0')
			return 0;
		a++; b++;
	}
	return *a - *b; 
}

int get_hash(char * data)
{
	int digest = 0;
	while (*data) {
		digest += *data;
		data++;
	}
	digest %= HL;
	return digest;
}

int add_to_ht(htn * node)
{
	htn * cur = NULL;

	if (!node) {
		printf("Node unavailable \n");
		return -1;
	}

	int hash = get_hash(node->data);

	if (ht[hash] == NULL) {
		ht[hash] = node;
		printf("node : %s added at %d \n", node->data, hash);
	} else {
		cur = ht[hash];
		while (cur->next != NULL)
			cur = cur->next;
		cur->next = node;
		printf("collision!!  -- chained and added - %s - %d \n",
				node->data, hash);
 	}	
	
	return hash;
}

int add_item(char *data)
{
	htn * node;

	if (data == NULL) {
		printf("Cannot add NULL data to ht\n");
		return -1;
	}
	
	node = (htn *) malloc(sizeof(htn));
	
	if (!node) {
		printf("Unable to allocate memory for %s\n", data);
		return -1;
	}
		
	node->data = (char *) malloc(sizeof(char) * strlen(data)+1);
	strcpy(node->data, data);

	node->next = NULL;

	return add_to_ht(node);
}

void print_ht()
{
	int i;
	for (i=0 ; i<HL ; i++) {
		if (ht[i] == NULL) {
			printf("ht[%d] = NULL \n", i);
		} else {
			htn * cur = ht[i];
			printf("ht[%d] = ", i);
			while (cur != NULL) {
				printf("\"%s\", ", cur->data);
				cur = cur->next;
			}
			printf("\n");	
		}
	}
}

int lookup(char *data)
{
	int hash = get_hash(data);
	htn * cur = NULL;
	int count = 0;

	if (ht[hash] == NULL) {
		printf("%s not found \n", data);
		return -1;
	}
	
	cur = ht[hash];
	while (cur) {
		count++;
		if (strcmp(cur->data, data) == 0) {
			printf("%s found with hash %d in %d lookups\n", data, hash, count);
			return hash;
		}
		cur = cur->next;
	}
	
	printf("%s not found \n", data);
	return -1;
}

int main()
{
	add_item("sangeeth");
	add_item("test");
	add_item("sangeeth");
	add_item("test");
	print_ht();
	lookup("data");
	lookup("sangeeth");

	add_item("Reporting");
	add_item("from");
	add_item("Washington—");
	add_item("The");
	add_item("threat");
	add_item("of");
	add_item("a");
	add_item("government");
	add_item("shutdown");
	add_item("intensified");
	add_item("as");
	add_item("the");
	add_item("House");
	add_item("surprised");
	add_item("its");
	add_item("Republican");
	add_item("leadership");
	add_item("and");
	add_item("rejected");
	add_item("a");
	add_item("bill");
	add_item("to");
	add_item("fund");
	add_item("the");
	add_item("government");
	add_item("that");
	add_item("required");
	add_item("cuts");
	add_item("in");
	add_item("programs");
	add_item("to");
	add_item("pay");
	add_item("for");
	add_item("aid");
	add_item("for");
	add_item("victims");
	add_item("of");
	add_item("Hurricane");
	add_item("Irene");
	add_item("and");
	add_item("other");
	add_item("disasters.");
	add_item("The");
	add_item("legislation");
	add_item("was");
	add_item("narrowly");
	add_item("defeated");
	add_item("Wednesday");
	add_item("after");
	add_item("a");
	add_item("tense");
	add_item("afternoon");
	add_item("of");
	add_item("vote");
	add_item("counting.");
	add_item("Conservatives");
	add_item("voted");
	add_item("against");
	add_item("the");
	add_item("bill");
	add_item("because");
	add_item("they");
	add_item("thought");
	add_item("its");
	add_item("spending");
	add_item("level");
	add_item("was");
	add_item("too");
	add_item("high,");
	add_item("and");
	add_item("Democrats");
	add_item("rejected");
	add_item("it");
	add_item("because");
	add_item("of");
	add_item("the");
	add_item("requirement");
	add_item("for");
	add_item("cuts.");
	add_item("The");
	add_item("spending");
	add_item("bill");
	add_item("is");
	add_item("needed");
	add_item("to");
	add_item("keep");
	add_item("the");
	add_item("government");
	add_item("running");
	add_item("through");
	add_item("Nov.");
	add_item("18;");
	add_item("current");
	add_item("spending");
	add_item("authority");
	add_item("stops");
	add_item("at");
	add_item("the");
	add_item("end");
	add_item("of");
	add_item("September.");
	add_item("House");
	add_item("Speaker");
	add_item("John");
	add_item("A.");
	add_item("Boehner");
	add_item("(R-Ohio)");
	add_item("had");
	add_item("hoped");
	add_item("to");
	add_item("avoid");
	add_item("another");
	add_item("budget");
	add_item("battle");
	add_item("in");
	add_item("the");
	add_item("wake");
	add_item("of");
	add_item("the");
	add_item("summer's");
	add_item("debt");
	add_item("ceiling");
	add_item("fight");
	add_item("and");
	add_item("a");
	add_item("near-shutdown");
	add_item("of");
	add_item("the");
	add_item("government");
	add_item("in");
	add_item("April");
	add_item("that");
	add_item("caused");
	add_item("voters");
	add_item("to");
	add_item("sour");
	add_item("on");
	add_item("Republicans");
	add_item("and");
	add_item("Democrats");
	add_item("in");
	add_item("Congress.");
	add_item("The");
	add_item("rebuke");
	add_item("gives");
	add_item("new");
	add_item("currency");
	add_item("to");
	add_item("Senate");
	add_item("Democrats'");
	add_item("efforts");
	add_item("to");
	add_item("fund");
	add_item("disaster");
	add_item("aid");
	add_item("without");
	add_item("cuts");
	add_item("elsewhere.");
	add_item("Congress");
	add_item("has");
	add_item("just");
	add_item("days");
	add_item("to");
	add_item("resolve");
	add_item("the");
	add_item("impasse");
	add_item("as");
	add_item("lawmakers");
	add_item("are");
	add_item("expected");
	add_item("to");
	add_item("recess");
	add_item("Friday");
	add_item("for");
	add_item("the");
	add_item("Jewish");
	add_item("holiday");
	add_item("of");
	add_item("Rosh");
	add_item("Hashana");
	add_item("next");
	add_item("week.");
	add_item("They're");
	add_item("threatening");
	add_item("to");
	add_item("shut");
	add_item("down");
	add_item("the");
	add_item("government");
	add_item("to");
	add_item("get");
	add_item("what");
	add_item("they");
	add_item("want,");
	add_item("Sen.");
	add_item("Harry");
	add_item("Reid");
	add_item("(D-Nev.),");
	add_item("the");
	add_item("majority");
	add_item("leader,");
	add_item("said");
	add_item("of");
	add_item("the");
	add_item("GOP-led");
	add_item("House.");
	add_item("House");
	add_item("Republican");
	add_item("leaders");
	add_item("huddled");
	add_item("late");
	add_item("Wednesday");
	add_item("to");
	add_item("consider");
	add_item("their");
	add_item("options.");
	add_item("It");
	add_item("is");
	add_item("unlikely");
	add_item("they");
	add_item("will");
	add_item("be");
	add_item("able");
	add_item("to");
	add_item("persuade");
	add_item("their");
	add_item("right");
	add_item("flank");
	add_item("to");
	add_item("support");
	add_item("a");
	add_item("bill");
	add_item("with");
	add_item("spending");
	add_item("levels");
	add_item("higher");
	add_item("than");
	add_item("they");
	add_item("want.");
	add_item("Instead,");
	add_item("Boehner");
	add_item("will");
	add_item("probably");
	add_item("be");
	add_item("forced");
	add_item("to");
	add_item("rely");
	add_item("on");
	add_item("Democrats");
	add_item("for");
	add_item("votes.");
	add_item("We");
	add_item("continue");
	add_item("to");
	add_item("work");
	add_item("on");
	add_item("a");
	add_item("responsible");
	add_item("plan");
	add_item("that");
	add_item("can");
	add_item("pass");
	add_item("the");
	add_item("House");
	add_item("said");
	add_item("Boehner");
	add_item("spokesman");
	add_item("Michael");
	add_item("Steel.");
	add_item("House");
	add_item("Minority");
	add_item("Leader");
	add_item("Nancy");
	add_item("Pelosi");
	add_item("(D-San");
	add_item("Francisco)");
	add_item("said");
	add_item("the");
	add_item("rejection");
	add_item("of");
	add_item("the");
	add_item("Republican");
	add_item("approach");
	add_item("left");
	add_item("the");
	add_item("GOP");
	add_item("leaders");
	add_item("few");
	add_item("options.");
	add_item("Now");
	add_item("it's");
	add_item("time");
	add_item("to");
	add_item("pass");
	add_item("the");
	add_item("Senate");
	add_item("disaster");
	add_item("aid");
	add_item("bill");
	add_item("she");
	add_item("said");
	add_item("in");
	add_item("a");
	add_item("Twitter");
	add_item("post.");
	add_item("Disaster");
	add_item("funding");
	add_item("typically");
	add_item("draws");
	add_item("bipartisan");
	add_item("support,");
	add_item("but");
	add_item("this");
	add_item("year");
	add_item("Republican");
	add_item("leaders");
	add_item("insisted");
	add_item("that");
	add_item("any");
	add_item("supplemental");
	add_item("emergency");
	add_item("funds");
	add_item("be");
	add_item("offset");
	add_item("by");
	add_item("spending");
	add_item("cuts.");
	add_item("After");
	add_item("a");
	add_item("year");
	add_item("of");
	add_item("floods,");
	add_item("tornadoes");
	add_item("and");
	add_item("recent");
	add_item("hurricanes");
	add_item("and");
	add_item("wildfires,");
	add_item("the");
	add_item("Federal");
	add_item("Emergency");
	add_item("Management");
	add_item("Agency's");
	add_item("disaster");
	add_item("fund");
	add_item("is");
	add_item("about");
	add_item("to");
	add_item("run");
	add_item("out");
	add_item("as");
	add_item("soon");
	add_item("as");
	add_item("Monday.");
	add_item("Already,");
	add_item("FEMA");
	add_item("has");
	add_item("prioritized");
	add_item("its");
	add_item("remaining");
	add_item("resources");
	add_item("to");
	add_item("provide");
	add_item("immediate");
	add_item("food,");
	add_item("water");
	add_item("and");
	add_item("debris");
	add_item("removal");
	add_item("for");
	add_item("recent");
	add_item("disasters,");
	add_item("while");
	add_item("longer-term");
	add_item("building");
	add_item("projects");
	add_item("are");
	add_item("on");
	add_item("hold.");
	add_item("To");
	add_item("pay");
	add_item("for");
	add_item("additional");
	add_item("aid");
	add_item("needed");
	add_item("to");
	add_item("cover");
	add_item("victims");
	add_item("of");
	add_item("Hurricane");
	add_item("Irene");
	add_item("and");
	add_item("other");
	add_item("recent");
	add_item("disasters,");
	add_item("the");
	add_item("House");
	add_item("bill");
	add_item("targeted");
	add_item("a");
	add_item("loan");
	add_item("program");
	add_item("for");
	add_item("alternative-energy");
	add_item("vehicle");
	add_item("manufacturing.");
	add_item("Democrats");
	add_item("opposed");
	add_item("cutting");
	add_item("funds");
	add_item("for");
	add_item("the");
	add_item("program");
	add_item("because");
	add_item("they");
	add_item("said");
	add_item("it");
	add_item("was");
	add_item("on");
	add_item("the");
	add_item("forefront");
	add_item("of");
	add_item("creating");
	add_item("green");
	add_item("jobs.");
	add_item("It's");
	add_item("with");
	add_item("great");
	add_item("sadness");
	add_item("that");
	add_item("we");
	add_item("even");
	add_item("have");
	add_item("to");
	add_item("have");
	add_item("a");
	add_item("debate");
	add_item("about");
	add_item("it");
	add_item("Pelosi");
	add_item("said");
	add_item("on");
	add_item("the");
	add_item("House");
	add_item("floor.");
	add_item("An");
	add_item("hour");
	add_item("before");
	add_item("the");
	add_item("vote,");
	add_item("GOP");
	add_item("leadership");
	add_item("did");
	add_item("not");
	add_item("know");
	add_item("whether");
	add_item("the");
	add_item("bill");
	add_item("would");
	add_item("pass.");
	add_item("Conservatives");
	add_item("in");
	add_item("the");
	add_item("House");
	add_item("resisted");
	add_item("the");
	add_item("overall");
	add_item("level");
	add_item("of");
	add_item("government");
	add_item("spending");
	add_item("for");
	add_item("fiscal");
	add_item("2012");
	add_item("as");
	add_item("too");
	add_item("high.");
	add_item("That");
	add_item("level");
	add_item("had");
	add_item("been");
	add_item("agreed");
	add_item("to");
	add_item("as");
	add_item("part");
	add_item("of");
	add_item("the");
	add_item("summer");
	add_item("debt");
	add_item("ceiling");
	add_item("deal,");
	add_item("but");
	add_item("was");
	add_item("$24");
	add_item("billion");
	add_item("more");
	add_item("than");
	add_item("House");
	add_item("Republicans");
	add_item("had");
	add_item("approved");
	add_item("in");
	add_item("their");
	add_item("own");
	add_item("budget.");
	add_item("If");
	add_item("I");
	add_item("put");
	add_item("this");
	add_item("to");
	add_item("my");
	add_item("constituents,");
	add_item("9");
	add_item("to");
	add_item("1,");
	add_item("they'd");
	add_item("say");
	add_item("no,");
	add_item("Rep.");
	add_item("Tim");
	add_item("Huelskamp");
	add_item("(R-Kan.)");
	add_item("said.");
	add_item("This");
	add_item("is");
	add_item("just");
	add_item("not");
	add_item("enough,");
	add_item("we");
	add_item("can");
	add_item("do");
	add_item("better");
	add_item("Boehner");
	add_item("made");
	add_item("a");
	add_item("plea");
	add_item("to");
	add_item("his");
	add_item("rank-and-file");
	add_item("members");
	add_item("to");
	add_item("unify");
	add_item("around");
	add_item("the");
	add_item("legislation.");
	add_item("Behind");
	add_item("closed");
	add_item("doors,");
	add_item("Boehner");
	add_item("told");
	add_item("lawmakers");
	add_item("that");
	add_item("a");
	add_item("failure");
	add_item("to");
	add_item("pass");
	add_item("the");
	add_item("bill");
	add_item("would");
	add_item("only");
	add_item("make");
	add_item("it");
	add_item("more");
	add_item("difficult");
	add_item("to");
	add_item("achieve");
	add_item("the");
	add_item("level");
	add_item("of");
	add_item("spending");
	add_item("Republicans");
	add_item("wanted.");
	add_item("Democrats");
	add_item("objected");
	add_item("to");
	add_item("the");
	add_item("disaster");
	add_item("provision.");
	add_item("Rep.");
	add_item("Kevin");
	add_item("McCarthy");
	add_item("(R-Bakersfield),");
	add_item("the");
	add_item("whip,");
	add_item("had");
	add_item("been");
	add_item("in");
	add_item("several");
	add_item("conversations");
	add_item("with");
	add_item("his");
	add_item("Democratic");
	add_item("counterpart,");
	add_item("Rep.");
	add_item("Steny");
	add_item("H.");
	add_item("Hoyer");
	add_item("(D-Md.),");
	add_item("to");
	add_item("gauge");
	add_item("how");
	add_item("many");
	add_item("Democrats");
	add_item("might");
	add_item("support");
	add_item("the");
	add_item("bill.");
	add_item("But");
	add_item("Democratic");
	add_item("leaders");
	add_item("urged");
	add_item("a");
	add_item("no");
	add_item("vote");
	add_item("and");
	add_item("only");
	add_item("six");
	add_item("Democrats");
	add_item("voted");
	add_item("for");
	add_item("the");
	add_item("measure.");
	add_item("Forty-eight");
	add_item("Republicans");
	add_item("also");
	add_item("opposed");
	add_item("the");
	add_item("measure,");
	add_item("which");
	add_item("failed,");
	add_item("195");
	add_item("to");
	add_item("230.");
	add_item("Even");
	add_item("the");
	add_item("Senate");
	add_item("bill");
	add_item("faces");
	add_item("a");
	add_item("difficult");
	add_item("route.");
	add_item("The");
	add_item("Senate");
	add_item("last");
	add_item("week");
	add_item("passed");
	add_item("a");
	add_item("larger");
	add_item("package");
	add_item("of");
	add_item("FEMA");
	add_item("aid");
	add_item("without");
	add_item("offsetting");
	add_item("spending");
	add_item("cuts");
	add_item("with");
	add_item("the");
	add_item("support");
	add_item("of");
	add_item("10");
	add_item("Republican");
	add_item("senators.");
	add_item("But");
	add_item("it");
	add_item("is");
	add_item("unclear");
	add_item("whether");
	add_item("those");
	add_item("senators");
	add_item("will");
	add_item("continue");
	add_item("supporting");
	add_item("the");
	add_item("disaster");
	add_item("package");
	add_item("now.");
	add_item("Sen.");
	add_item("Mary");
	add_item("L.");
	add_item("Landrieu");
	add_item("(D-La.),");
	add_item("a");
	add_item("champion");
	add_item("of");
	add_item("the");
	add_item("aid");
	add_item("package,");
	add_item("began");
	add_item("calling");
	add_item("out");
	add_item("some");
	add_item("of");
	add_item("those");
	add_item("10");
	add_item("senators,");
	add_item("pressuring");
	add_item("them");
	add_item("not");
	add_item("to");
	add_item("change");
	add_item("their");
	add_item("position.");

	print_ht();
	lookup("is");
	lookup("Even");
	lookup("Evan");

	return 0;
}



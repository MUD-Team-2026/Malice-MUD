#include "OtherNPC.h"

Reiko::Reiko() : NPC() {}
Reiko::Reiko(const string& id, const string& name, const string& desc)
    : NPC(id, name, desc) {}

string Reiko::getFirstDialog() {
    return "理惠擦了擦眼泪：\"邦彦他……是个温柔的人。\n"
           "他经常帮助朋友，从来不求回报。\n"
           "我不相信他会做出胁迫别人的事……\"";
}

string Reiko::getDialog(const string& playerInput) {
    if (playerInput.find("日高") != string::npos || playerInput.find("邦彦") != string::npos) {
        return "理惠：\"邦彦和野野口先生是中学同学。\n"
               "邦彦经常提起他，说他很有才华，只是缺少机会……\"";
    }
    return getFirstDialog();
}

Teacher::Teacher() : NPC() {}
Teacher::Teacher(const string& id, const string& name, const string& desc)
    : NPC(id, name, desc) {}

string Teacher::getFirstDialog() {
    return "老师叹了口气：\"日高那孩子……\n"
           "其实当年被欺负得最惨的是他。\n"
           "野野口是跟着施暴者一起欺辱日高的帮凶。\"";
}

string Teacher::getDialog(const string& playerInput) {
    if (playerInput.find("野野口") != string::npos) {
        return "老师：\"野野口那时候总是跟在那些坏学生后面。\n"
               "他不敢欺负日高，但也从来没有帮过日高。\"";
    }
    return getFirstDialog();
}

Fujio::Fujio() : NPC() {}
Fujio::Fujio(const string& id, const string& name, const string& desc)
    : NPC(id, name, desc) {}

string Fujio::getFirstDialog() {
    return "藤尾：\"日高是唯一站出来救我的人。\n"
           "那时候我被一群人欺负，只有日高敢站出来说话。\n"
           "野野口？他在旁边帮施暴者把风。\"";
}

string Fujio::getDialog(const string& playerInput) {
    if (playerInput.find("野野口") != string::npos) {
        return "藤尾：\"野野口那家伙……从来不敢自己动手，\n"
               "只会在旁边看着，或者帮他们望风。\n"
               "说实话，我觉得他比那些施暴者更可恨。\"";
    }
    return getFirstDialog();
}

Neighbor::Neighbor() : NPC() {}
Neighbor::Neighbor(const string& id, const string& name, const string& desc)
    : NPC(id, name, desc) {}

string Neighbor::getFirstDialog() {
    return "邻居太太气愤地说：\"日高先生？他表面上是作家，\n"
           "实际上很可怕！他毒死了我家的猫！\n"
           "我亲眼看到他在院子里撒毒药……\"";
}

string Neighbor::getDialog(const string& playerInput) {
    if (playerInput.find("猫") != string::npos || playerInput.find("毒") != string::npos) {
        return "邻居太太：\"我家的猫死的时候太惨了……\n"
               "一定是日高干的！那个伪君子！\"\n"
               "（但她的说法和药店老板的证词有矛盾……）";
    }
    return getFirstDialog();
}

Pharmacist::Pharmacist() : NPC() {}
Pharmacist::Pharmacist(const string& id, const string& name, const string& desc)
    : NPC(id, name, desc) {}

string Pharmacist::getFirstDialog() {
    return "药店老板：\"啊，野野口先生上个月来买过山埃，\n"
           "说是家里有老鼠。\n"
           "那种药可危险了，我特意问了他好几遍……\"";
}

string Pharmacist::getDialog(const string& playerInput) {
    if (playerInput.find("山埃") != string::npos || playerInput.find("毒药") != string::npos) {
        return "药店老板：\"我记得很清楚，是上个月15号。\n"
               "他买的量很大，说是家里鼠患严重……\n"
               "现在想想，那时候日高先生还没出事呢。\"";
    }
    return getFirstDialog();
}

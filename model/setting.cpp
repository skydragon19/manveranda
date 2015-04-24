#include "setting.h"

struct settings set ;

setting::setting()
{
}

void setting::read_setting(){
    QString pth = "veranda_set.ini";
    QSettings sett(pth, QSettings::IniFormat);

    set.host = sett.value("hostname").toString();
    set.name = sett.value("databasename").toString();
    set.user = sett.value("username").toString();
    set.pass = sett.value("password").toString();
}

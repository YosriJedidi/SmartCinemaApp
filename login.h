#ifndef LOGIN_H
#define LOGIN_H
#include <QString>

class Login
{
public:
    Login();
    Login(int,QString);
    int connect(int id, QString mdp);
private:
    int id;
    QString mdp;
};

#endif // LOGIN_H

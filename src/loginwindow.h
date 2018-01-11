#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QAbstractItemModel>
#include <QSharedPointer>
#include <QLightDM/Greeter>
#include <QLightDM/UsersModel>
#include "iconedit.h"
#include "greeterwrapper.h"

class LoginWindow : public QWidget
{
    Q_OBJECT
public:
    explicit LoginWindow(QSharedPointer<GreeterWrapper> greeter, QWidget *parent = 0);
    ~LoginWindow(){}

    void addMessage(const QString &);
    void setModel(QSharedPointer<QAbstractItemModel> model);
    bool setIndex(const QModelIndex& index);
    void setGreeter(QSharedPointer<GreeterWrapper> greeter);
private:
    void initUI();

protected:
    bool eventFilter(QObject *, QEvent *);

signals:
    void back();

public slots:

    void showMessage_cb(QString text, QLightDM::Greeter::MessageType type);
    void showPrompt_cb(QString text, QLightDM::Greeter::PromptType type);
    void authenticationComplete_cb();
    void autologinTimerExpired_cb();
    void reset_cb();
    void login_cb(const QString &str);

private:
    QSharedPointer<QAbstractItemModel> m_model;
    QSharedPointer<GreeterWrapper> m_greeter;

    QLabel  *m_backLabel;         //返回用户列表
    QLabel  *m_faceLabel;         //头像
    QLabel  *m_nameLabel;         //用户名
    QLabel  *m_isLoginLabel;      //提示是否已登录
    QLabel  *m_messageLabel;      //提示信息
    IconEdit *m_passwordEdit;     //密码

};

#endif // LOGINWINDOW_H

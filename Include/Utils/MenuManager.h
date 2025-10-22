#ifndef MENUMANAGER_HPP 
#define MENUMANAGER_HPP
#include <QWidget>
#include <QStackedWidget>
#include <QString>
#include <QStack>
#include <unordered_map>
#include "BaseMenu.h"
#include "Parser.h"

class MenuManager: public QWidget
{
    Q_OBJECT
public:
    explicit MenuManager(Parser& parser, QWidget* parent = nullptr);
    void showMenu(const QString& name);
    BaseMenu* getMenu(const QString& name) const;
private: 
    void buildMenus(Parser& parser);
    QStackedWidget* stacked;
    QStack<QWidget*> history; 
};

#endif 


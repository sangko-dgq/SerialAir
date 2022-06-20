
# Qtdesigner中使⽤QSplitter创建推拉窗⼝

### 典型例⼦：在Widgets上左边放置树形菜单，右边放置⽂本框等其他框架，需要实现菜单的边界可以推拉。

1. **method 1：代码实现⽅法**

```C++
QSplitter *splitter = new QSplitter(parent);
QListView *listview = new QListView;
QTreeView *treeview = new QTreeView;
QTextEdit *textedit = new QTextEdit;
splitter->addWidget(listview);
splitter->addWidget(treeview);
splitter->addWidget(textedit);
```

**method 2：Qt designer实现**
适⽤于多控件的场景

1. 选中需要分裂的两个部件；
2. 右击布局，选中使⽤**分裂器**⽔平布局，如果垂直分裂，则选择使⽤分裂器垂直布局即可；
3. 再对widgets进⾏grid**⽹格**布局；
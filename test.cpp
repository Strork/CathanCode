void MainWindow::on_pushButton_clicked()
{
    QSqlQuery query;
    query.exec("select * from student");
    qDebug() << "exec next() :";
    //开始就先执行一次next()函数，那么query指向结果集的第一条记录
if(query.next()) {
    int rowNum = query.at();//获取query所指向的记录在结果集中的编号
    int columnNum = query.record().count();//获取每条记录中属性（即列）的个数
    int fieldNo = query.record().indexOf("name");
    //获取"name"属性所在列的编号，列从左向右编号，最左边的编号为0
    int id = query.value(0).toInt();//获取id属性的值，并转换为int型
    QString name = query.value(fieldNo).toString();//获取name属性的值
    //将结果输出
    qDebug() << "rowNum is : " << rowNum
                << " id is : " << id
                << " name is : " << name
                << " columnNum is : " << columnNum;
}
//定位到结果集中编号为2的记录，即第三条记录，因为第一条记录的编号为0
    qDebug() << "exec seek(2) :";
    if(query.seek(2))
    {
       qDebug() << "rowNum is : " << query.at()
                 << " id is : " << query.value(0).toInt()
                 << " name is : " << query.value(1).toString();
    }
    //定位到结果集中最后一条记录
    qDebug() << "exec last() :";
    if(query.last())
    {
       qDebug() << "rowNum is : " << query.at()
                 << " id is : " << query.value(0).toInt()
                 << " name is : " << query.value(1).toString();
    }
}

/*QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    QString db_dir = QCoreApplication::applicationDirPath() + QString("/factory.db");
    qDebug() << db_dir;
    db.setDatabaseName(db_dir);
    if (!db.open()) {
        qDebug() << "error:" << db.lastError().text();
    }
    else {
        qDebug() << "connected";
    }

    QSqlQuery query;
    qDebug() << query.exec("CREATE TABLE IF NOT EXISTS sensor(id INT PRIMARU KEY AUTOINCREMENT,"
               "name varchar(64),"
               "equip_id int,"
               "buyday DATE);");
    qDebug() << query.exec("CREATE TABLE IF NOT EXISTS equipment(id INT NOT NULL,"
               "name VARCHAR (64),"
               "sensor_id INT DEFAULT 0,"
               "buyday DATE,"
               "PRIMARY KEY (id, sensor_id));");

    qDebug() << query.exec("select * from sensor");
    while(query.next()) {
        qDebug() << query.value(0).toInt()
                 << query.value(1)
                 << query.value("equip")
                 << query.value("buytime");
    }
    db.close();*/
//
// Created by zhaojunhe on 2018/11/29.
//

#include <QFile>
#include <QDir>
#include <QTextStream>
#include <QDebug>

int main() {
    QFile route(":test_result_1130.txt");
    QFile route2(QDir::currentPath() + "/test_result_2.txt");
    if (!route.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "route don't open.";
    }
    if (route2.exists()) {
        route2.remove();
    }
    if (!route2.open(QIODevice::ReadWrite | QIODevice::Text)) {
        qDebug() << "route2 don't open.";
    }
    QTextStream in(&route);

    int line_index = 0;

    int parse = 0;
    int loaded = 0;
    int first = 0;
    int fps = 0;
    float cpu = 0.0f;
    float max_cpu = 0.0f;
    float min_cpu = 0.0f;
    float tp70_cpu = 0.0f;
    float mem = 0.0f;
    float max_mem = 0.0f;
    float min_mem = 0.0f;
    float tp70_mem = 0.0f;
    float traffic = 0.0f;
    float power = 0.0f;

    while (!in.atEnd()) {
        QString line = in.readLine();
        qDebug() << line;
        QStringList str_list = line.split(" ");

//        double mem = str_list[10].toFloat() / 1024.0f / 1024.0f;
//        str_list[10] = QString::number(mem, 5, 2);
//        double max_mem = str_list[11].toFloat() / 1024.0f / 1024.0f;
//        str_list[11] = QString::number(max_mem, 5, 2);
//        double min_mem = str_list[12].toFloat() / 1024.0f / 1024.0f;
//        str_list[12] = QString::number(min_mem, 5, 2);
//        double p70_mem = str_list[13].toFloat() / 1024.0f / 1024.0f;
//        str_list[13] = QString::number(p70_mem, 5, 2);

        parse += str_list[2].toInt();
        loaded += str_list[3].toInt();
        first += str_list[4].toInt();
        fps += str_list[5].toInt();
        cpu += str_list[6].toFloat();
        max_cpu += str_list[7].toFloat();
        min_cpu += str_list[8].toFloat();
        tp70_cpu += str_list[9].toFloat();
        mem += str_list[10].toFloat();
        max_mem += str_list[11].toFloat();
        min_mem += str_list[12].toFloat();
        tp70_mem += str_list[13].toFloat();
        traffic += str_list[14].toFloat();
        power += str_list[15].toFloat();

        QString line2;
        for (auto str:str_list) {
            qDebug() << str;
            line2 += str + " ";
        }
        line2 += "\n";

        if ((line_index + 1) % 6 == 0) {
            line2 += "avg: " + QString("%1").arg(parse / 6) + " " + QString("%1").arg(loaded / 6) + " " +
                     QString("%1").arg(first / 6) + " " + QString("%1").arg(fps / 6) + " " +
                     QString("%1").arg(cpu / 6) + " " + QString("%1").arg(max_cpu / 6) + " " +
                     QString("%1").arg(min_cpu / 6) + " " + QString("%1").arg(tp70_cpu / 6) + " " +
                     QString("%1").arg(mem / 6) + " " + QString("%1").arg(max_mem / 6) + " " +
                     QString("%1").arg(min_mem / 6) + " " + QString("%1").arg(tp70_mem / 6) + " " +
                     QString("%1").arg(traffic / 6) + " " + QString("%1").arg(power / 6) + " ";
            line2 += "\n";
            line2 += "\n";

            parse = 0;
            loaded = 0;
            first = 0;
            fps = 0;
            cpu = 0.0f;
            max_cpu = 0.0f;
            min_cpu = 0.0f;
            tp70_cpu = 0.0f;
            mem = 0.0f;
            max_mem = 0.0f;
            min_mem = 0.0f;
            tp70_mem = 0.0f;
            traffic = 0.0f;
            power = 0.0f;
        }

        route2.write(line2.toStdString().c_str());

        line_index++;
    }
}


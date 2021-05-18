#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QDebug>
#include <QDir>
#include <QtPlugin>
#include <QQmlExtensionPlugin>

Q_IMPORT_PLUGIN(MyPlugin)

int main(int argc, char *argv[]) {
    Q_INIT_RESOURCE(plugin);
#if defined(Q_OS_WIN)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

qobject_cast<QQmlExtensionPlugin*>(qt_static_plugin_MyPlugin().instance())->registerTypes("my.plugin.example");

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    // Add import search path
    engine.addImportPath(":/");
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty()) {
        return -1;
    }

    return app.exec();
}

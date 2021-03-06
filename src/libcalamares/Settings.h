/* === This file is part of Calamares - <https://github.com/calamares> ===
 *
 *   Copyright 2014-2015, Teo Mrnjavac <teo@kde.org>
 *   Copyright 2017, Adriaan de Groot <groot@kde.org>
 *
 *   Calamares is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   Calamares is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with Calamares. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef SETTINGS_H
#define SETTINGS_H

#include "UiDllMacro.h"
#include "Typedefs.h"

#include <QObject>
#include <QStringList>


namespace Calamares
{

class UIDLLEXPORT Settings : public QObject
{
    Q_OBJECT
public:
    explicit Settings( const QString& settingsFilePath,
                       bool debugMode,
                       QObject* parent = nullptr );

    static Settings* instance();
    //TODO: load from YAML then emit ready

    QStringList modulesSearchPaths() const;

    using InstanceDescription = QMap< QString, QString >;
    using InstanceDescriptionList = QList< InstanceDescription >;
    InstanceDescriptionList customModuleInstances() const;

    QList< QPair< ModuleAction, QStringList > > modulesSequence() const;

    QString brandingComponentName() const;

    bool showPromptBeforeExecution() const;

    bool debugMode() const;

    bool doChroot() const;

private:
    static Settings* s_instance;

    QStringList m_modulesSearchPaths;

    InstanceDescriptionList m_customModuleInstances;
    QList< QPair< ModuleAction, QStringList > > m_modulesSequence;

    QString m_brandingComponentName;

    bool m_debug;
    bool m_doChroot;
    bool m_promptInstall;
};

}

#endif // SETTINGS_H

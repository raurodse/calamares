/* === This file is part of Calamares - <https://github.com/calamares> ===
 *
 *   Copyright 2014, Teo Mrnjavac <teo@kde.org>
 *   Copyright 2017-2018, Adriaan de Groot <groot@kde.org>
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

#ifndef YAMLUTILS_H
#define YAMLUTILS_H

#include <QStringList>
#include <QVariant>

class QByteArray;
class QFileInfo;

namespace YAML
{
class Node;
class Exception;
}

void operator>>( const YAML::Node& node, QStringList& v );

namespace CalamaresUtils
{
/**
 * Loads a given @p filename and returns the YAML data
 * as a QVariantMap. If filename doesn't exist, or is
 * malformed in some way, returns an empty map and sets
 * @p *ok to false. Otherwise sets @p *ok to true.
 */
QVariantMap loadYaml( const QString& filename, bool* ok = nullptr );
/** Convenience overload. */
QVariantMap loadYaml( const QFileInfo&, bool* ok = nullptr );

QVariant yamlToVariant( const YAML::Node& node );
QVariant yamlScalarToVariant( const YAML::Node& scalarNode );
QVariant yamlSequenceToVariant( const YAML::Node& sequenceNode );
QVariant yamlMapToVariant( const YAML::Node& mapNode );

/**
 * Given an exception from the YAML parser library, explain
 * what is going on in terms of the data passed to the parser.
 * Uses @p label when labeling the data source (e.g. "netinstall data")
 */
void explainYamlException( const YAML::Exception& e, const QByteArray& data, const char *label );
void explainYamlException( const YAML::Exception& e, const QByteArray& data, const QString& label );
void explainYamlException( const YAML::Exception& e, const QByteArray& data );

} //ns

#endif // YAMLUTILS_H

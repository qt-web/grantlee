/*
  This file is part of the Grantlee template system.

  Copyright (c) 2009 Stephen Kelly <steveire@gmail.com>

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License version 3 only, as published by the Free Software Foundation.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License version 3 for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library.  If not, see <http://www.gnu.org/licenses/>.

*/

#ifndef ENGINE_H
#define ENGINE_H

#include "template.h"
#include "mutabletemplate.h"
#include "interfaces/taglibraryinterface.h"
#include "templateloader.h"

namespace Grantlee
{

class EnginePrivate;

class GRANTLEE_EXPORT Engine
{
public:
  static Engine* instance();

  ~Engine();

  QList<AbstractTemplateLoader::Ptr> templateLoaders( qint64 settingsToken = 0 );
  void addTemplateLoader( AbstractTemplateLoader::Ptr loader, qint64 settingsToken = 0 );
  void removeTemplateLoader( int index, qint64 settingsToken = 0 );

  void setPluginDirs( const QStringList &dirs, qint64 settingsToken = 0 );
  QStringList pluginDirs( qint64 settingsToken = 0 );

  QString mediaUri( const QString &fileName, qint64 settingsToken = 0 ) const;

  /**
  Causes a state transition if settingsToken is 0.
  */
  Template loadByName( const QString &name, qint64 settingsToken = 0 ) const;

  /**
  Causes a state transition if settingsToken is 0.
  */
  Template newTemplate( const QString &content, const QString &name, qint64 settingsToken = 0 );

  /**
  Causes a state transition if settingsToken is 0.
  */
  MutableTemplate loadMutableByName( const QString &name, qint64 settingsToken = 0 ) const;

  /**
  Causes a state transition if settingsToken is 0.
  */
  MutableTemplate newMutableTemplate( const QString &content, const QString &name, qint64 settingsToken = 0 );

  QStringList defaultLibraries( qint64 settingsToken = 0 ) const;
  void setDefaultLibraries( const QStringList &list, qint64 settingsToken = 0 );
  void addDefaultLibrary( const QString &libName, qint64 settingsToken = 0 );
  void removeDefaultLibrary( const QString &libName, qint64 settingsToken = 0 );

  QList<TagLibraryInterface*> loadDefaultLibraries( qint64 settingsToken = 0 );

  TagLibraryInterface* loadLibrary( const QString &name, qint64 settingsToken = 0 );

private:
  Engine();

  Q_DECLARE_PRIVATE( Engine )
  EnginePrivate *d_ptr;

  static Engine* m_instance;
  friend class EngineStateImpl;
};

}

#endif


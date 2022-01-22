package com.amaze.filemanager.database.daos;

import android.database.Cursor;
import androidx.room.EmptyResultSetException;
import androidx.room.EntityDeletionOrUpdateAdapter;
import androidx.room.EntityInsertionAdapter;
import androidx.room.RoomDatabase;
import androidx.room.RoomSQLiteQuery;
import androidx.room.RxRoom;
import androidx.room.util.CursorUtil;
import androidx.room.util.DBUtil;
import androidx.sqlite.db.SupportSQLiteStatement;
import com.amaze.filemanager.database.models.StringWrapper;
import com.amaze.filemanager.database.models.explorer.CloudEntry;
import com.amaze.filemanager.database.typeconverters.EncryptedStringTypeConverter;
import com.amaze.filemanager.database.typeconverters.OpenModeTypeConverter;
import com.amaze.filemanager.file_operations.filesystem.OpenMode;
import io.reactivex.Completable;
import io.reactivex.Single;
import java.lang.Exception;
import java.lang.Override;
import java.lang.String;
import java.lang.SuppressWarnings;
import java.lang.Void;
import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.Callable;

@SuppressWarnings({"unchecked", "deprecation"})
public final class CloudEntryDao_Impl implements CloudEntryDao {
  private final RoomDatabase __db;

  private final EntityInsertionAdapter<CloudEntry> __insertionAdapterOfCloudEntry;

  private final EntityDeletionOrUpdateAdapter<CloudEntry> __deletionAdapterOfCloudEntry;

  private final EntityDeletionOrUpdateAdapter<CloudEntry> __updateAdapterOfCloudEntry;

  public CloudEntryDao_Impl(RoomDatabase __db) {
    this.__db = __db;
    this.__insertionAdapterOfCloudEntry = new EntityInsertionAdapter<CloudEntry>(__db) {
      @Override
      public String createQuery() {
        return "INSERT OR ABORT INTO `cloud` (`_id`,`service`,`persist`) VALUES (nullif(?, 0),?,?)";
      }

      @Override
      public void bind(SupportSQLiteStatement stmt, CloudEntry value) {
        stmt.bindLong(1, value.getId());
        final int _tmp;
        _tmp = OpenModeTypeConverter.fromOpenMode(value.getServiceType());
        stmt.bindLong(2, _tmp);
        final String _tmp_1;
        _tmp_1 = EncryptedStringTypeConverter.fromPassword(value.getPersistData());
        if (_tmp_1 == null) {
          stmt.bindNull(3);
        } else {
          stmt.bindString(3, _tmp_1);
        }
      }
    };
    this.__deletionAdapterOfCloudEntry = new EntityDeletionOrUpdateAdapter<CloudEntry>(__db) {
      @Override
      public String createQuery() {
        return "DELETE FROM `cloud` WHERE `_id` = ?";
      }

      @Override
      public void bind(SupportSQLiteStatement stmt, CloudEntry value) {
        stmt.bindLong(1, value.getId());
      }
    };
    this.__updateAdapterOfCloudEntry = new EntityDeletionOrUpdateAdapter<CloudEntry>(__db) {
      @Override
      public String createQuery() {
        return "UPDATE OR ABORT `cloud` SET `_id` = ?,`service` = ?,`persist` = ? WHERE `_id` = ?";
      }

      @Override
      public void bind(SupportSQLiteStatement stmt, CloudEntry value) {
        stmt.bindLong(1, value.getId());
        final int _tmp;
        _tmp = OpenModeTypeConverter.fromOpenMode(value.getServiceType());
        stmt.bindLong(2, _tmp);
        final String _tmp_1;
        _tmp_1 = EncryptedStringTypeConverter.fromPassword(value.getPersistData());
        if (_tmp_1 == null) {
          stmt.bindNull(3);
        } else {
          stmt.bindString(3, _tmp_1);
        }
        stmt.bindLong(4, value.getId());
      }
    };
  }

  @Override
  public Completable insert(final CloudEntry entry) {
    return Completable.fromCallable(new Callable<Void>() {
      @Override
      public Void call() throws Exception {
        __db.beginTransaction();
        try {
          __insertionAdapterOfCloudEntry.insert(entry);
          __db.setTransactionSuccessful();
          return null;
        } finally {
          __db.endTransaction();
        }
      }
    });
  }

  @Override
  public Completable delete(final CloudEntry entry) {
    return Completable.fromCallable(new Callable<Void>() {
      @Override
      public Void call() throws Exception {
        __db.beginTransaction();
        try {
          __deletionAdapterOfCloudEntry.handle(entry);
          __db.setTransactionSuccessful();
          return null;
        } finally {
          __db.endTransaction();
        }
      }
    });
  }

  @Override
  public Completable update(final CloudEntry entry) {
    return Completable.fromCallable(new Callable<Void>() {
      @Override
      public Void call() throws Exception {
        __db.beginTransaction();
        try {
          __updateAdapterOfCloudEntry.handle(entry);
          __db.setTransactionSuccessful();
          return null;
        } finally {
          __db.endTransaction();
        }
      }
    });
  }

  @Override
  public Single<CloudEntry> findByServiceType(final int serviceType) {
    final String _sql = "SELECT `cloud`.`_id` AS `_id`, `cloud`.`service` AS `service`, `cloud`.`persist` AS `persist` FROM cloud WHERE service = ?";
    final RoomSQLiteQuery _statement = RoomSQLiteQuery.acquire(_sql, 1);
    int _argIndex = 1;
    _statement.bindLong(_argIndex, serviceType);
    return RxRoom.createSingle(new Callable<CloudEntry>() {
      @Override
      public CloudEntry call() throws Exception {
        final Cursor _cursor = DBUtil.query(__db, _statement, false, null);
        try {
          final int _cursorIndexOfId = CursorUtil.getColumnIndexOrThrow(_cursor, "_id");
          final int _cursorIndexOfServiceType = CursorUtil.getColumnIndexOrThrow(_cursor, "service");
          final int _cursorIndexOfPersistData = CursorUtil.getColumnIndexOrThrow(_cursor, "persist");
          final CloudEntry _result;
          if(_cursor.moveToFirst()) {
            _result = new CloudEntry();
            final int _tmp_id;
            _tmp_id = _cursor.getInt(_cursorIndexOfId);
            _result.setId(_tmp_id);
            final OpenMode _tmpServiceType;
            final int _tmp;
            _tmp = _cursor.getInt(_cursorIndexOfServiceType);
            _tmpServiceType = OpenModeTypeConverter.fromDatabaseValue(_tmp);
            _result.setServiceType(_tmpServiceType);
            final StringWrapper _tmpPersistData;
            final String _tmp_1;
            _tmp_1 = _cursor.getString(_cursorIndexOfPersistData);
            _tmpPersistData = EncryptedStringTypeConverter.toPassword(_tmp_1);
            _result.setPersistData(_tmpPersistData);
          } else {
            _result = null;
          }
          if(_result == null) {
            throw new EmptyResultSetException("Query returned empty result set: " + _statement.getSql());
          }
          return _result;
        } finally {
          _cursor.close();
        }
      }

      @Override
      protected void finalize() {
        _statement.release();
      }
    });
  }

  @Override
  public Single<List<CloudEntry>> list() {
    final String _sql = "SELECT `cloud`.`_id` AS `_id`, `cloud`.`service` AS `service`, `cloud`.`persist` AS `persist` FROM cloud";
    final RoomSQLiteQuery _statement = RoomSQLiteQuery.acquire(_sql, 0);
    return RxRoom.createSingle(new Callable<List<CloudEntry>>() {
      @Override
      public List<CloudEntry> call() throws Exception {
        final Cursor _cursor = DBUtil.query(__db, _statement, false, null);
        try {
          final int _cursorIndexOfId = CursorUtil.getColumnIndexOrThrow(_cursor, "_id");
          final int _cursorIndexOfServiceType = CursorUtil.getColumnIndexOrThrow(_cursor, "service");
          final int _cursorIndexOfPersistData = CursorUtil.getColumnIndexOrThrow(_cursor, "persist");
          final List<CloudEntry> _result = new ArrayList<CloudEntry>(_cursor.getCount());
          while(_cursor.moveToNext()) {
            final CloudEntry _item;
            _item = new CloudEntry();
            final int _tmp_id;
            _tmp_id = _cursor.getInt(_cursorIndexOfId);
            _item.setId(_tmp_id);
            final OpenMode _tmpServiceType;
            final int _tmp;
            _tmp = _cursor.getInt(_cursorIndexOfServiceType);
            _tmpServiceType = OpenModeTypeConverter.fromDatabaseValue(_tmp);
            _item.setServiceType(_tmpServiceType);
            final StringWrapper _tmpPersistData;
            final String _tmp_1;
            _tmp_1 = _cursor.getString(_cursorIndexOfPersistData);
            _tmpPersistData = EncryptedStringTypeConverter.toPassword(_tmp_1);
            _item.setPersistData(_tmpPersistData);
            _result.add(_item);
          }
          if(_result == null) {
            throw new EmptyResultSetException("Query returned empty result set: " + _statement.getSql());
          }
          return _result;
        } finally {
          _cursor.close();
        }
      }

      @Override
      protected void finalize() {
        _statement.release();
      }
    });
  }
}

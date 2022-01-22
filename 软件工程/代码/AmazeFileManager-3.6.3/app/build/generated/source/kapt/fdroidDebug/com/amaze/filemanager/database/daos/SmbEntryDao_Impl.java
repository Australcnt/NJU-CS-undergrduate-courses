package com.amaze.filemanager.database.daos;

import android.database.Cursor;
import androidx.room.EmptyResultSetException;
import androidx.room.EntityDeletionOrUpdateAdapter;
import androidx.room.EntityInsertionAdapter;
import androidx.room.RoomDatabase;
import androidx.room.RoomSQLiteQuery;
import androidx.room.RxRoom;
import androidx.room.SharedSQLiteStatement;
import androidx.room.util.CursorUtil;
import androidx.room.util.DBUtil;
import androidx.sqlite.db.SupportSQLiteStatement;
import com.amaze.filemanager.database.models.utilities.SmbEntry;
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
public final class SmbEntryDao_Impl implements SmbEntryDao {
  private final RoomDatabase __db;

  private final EntityInsertionAdapter<SmbEntry> __insertionAdapterOfSmbEntry;

  private final EntityDeletionOrUpdateAdapter<SmbEntry> __updateAdapterOfSmbEntry;

  private final SharedSQLiteStatement __preparedStmtOfDeleteByName;

  private final SharedSQLiteStatement __preparedStmtOfDeleteByNameAndPath;

  public SmbEntryDao_Impl(RoomDatabase __db) {
    this.__db = __db;
    this.__insertionAdapterOfSmbEntry = new EntityInsertionAdapter<SmbEntry>(__db) {
      @Override
      public String createQuery() {
        return "INSERT OR ABORT INTO `smb` (`_id`,`path`,`name`) VALUES (nullif(?, 0),?,?)";
      }

      @Override
      public void bind(SupportSQLiteStatement stmt, SmbEntry value) {
        stmt.bindLong(1, value._id);
        if (value.path == null) {
          stmt.bindNull(2);
        } else {
          stmt.bindString(2, value.path);
        }
        if (value.name == null) {
          stmt.bindNull(3);
        } else {
          stmt.bindString(3, value.name);
        }
      }
    };
    this.__updateAdapterOfSmbEntry = new EntityDeletionOrUpdateAdapter<SmbEntry>(__db) {
      @Override
      public String createQuery() {
        return "UPDATE OR ABORT `smb` SET `_id` = ?,`path` = ?,`name` = ? WHERE `_id` = ?";
      }

      @Override
      public void bind(SupportSQLiteStatement stmt, SmbEntry value) {
        stmt.bindLong(1, value._id);
        if (value.path == null) {
          stmt.bindNull(2);
        } else {
          stmt.bindString(2, value.path);
        }
        if (value.name == null) {
          stmt.bindNull(3);
        } else {
          stmt.bindString(3, value.name);
        }
        stmt.bindLong(4, value._id);
      }
    };
    this.__preparedStmtOfDeleteByName = new SharedSQLiteStatement(__db) {
      @Override
      public String createQuery() {
        final String _query = "DELETE FROM smb WHERE name = ?";
        return _query;
      }
    };
    this.__preparedStmtOfDeleteByNameAndPath = new SharedSQLiteStatement(__db) {
      @Override
      public String createQuery() {
        final String _query = "DELETE FROM smb WHERE name = ? AND path = ?";
        return _query;
      }
    };
  }

  @Override
  public Completable insert(final SmbEntry instance) {
    return Completable.fromCallable(new Callable<Void>() {
      @Override
      public Void call() throws Exception {
        __db.beginTransaction();
        try {
          __insertionAdapterOfSmbEntry.insert(instance);
          __db.setTransactionSuccessful();
          return null;
        } finally {
          __db.endTransaction();
        }
      }
    });
  }

  @Override
  public Completable update(final SmbEntry instance) {
    return Completable.fromCallable(new Callable<Void>() {
      @Override
      public Void call() throws Exception {
        __db.beginTransaction();
        try {
          __updateAdapterOfSmbEntry.handle(instance);
          __db.setTransactionSuccessful();
          return null;
        } finally {
          __db.endTransaction();
        }
      }
    });
  }

  @Override
  public Completable deleteByName(final String name) {
    return Completable.fromCallable(new Callable<Void>() {
      @Override
      public Void call() throws Exception {
        final SupportSQLiteStatement _stmt = __preparedStmtOfDeleteByName.acquire();
        int _argIndex = 1;
        if (name == null) {
          _stmt.bindNull(_argIndex);
        } else {
          _stmt.bindString(_argIndex, name);
        }
        __db.beginTransaction();
        try {
          _stmt.executeUpdateDelete();
          __db.setTransactionSuccessful();
          return null;
        } finally {
          __db.endTransaction();
          __preparedStmtOfDeleteByName.release(_stmt);
        }
      }
    });
  }

  @Override
  public Completable deleteByNameAndPath(final String name, final String path) {
    return Completable.fromCallable(new Callable<Void>() {
      @Override
      public Void call() throws Exception {
        final SupportSQLiteStatement _stmt = __preparedStmtOfDeleteByNameAndPath.acquire();
        int _argIndex = 1;
        if (name == null) {
          _stmt.bindNull(_argIndex);
        } else {
          _stmt.bindString(_argIndex, name);
        }
        _argIndex = 2;
        if (path == null) {
          _stmt.bindNull(_argIndex);
        } else {
          _stmt.bindString(_argIndex, path);
        }
        __db.beginTransaction();
        try {
          _stmt.executeUpdateDelete();
          __db.setTransactionSuccessful();
          return null;
        } finally {
          __db.endTransaction();
          __preparedStmtOfDeleteByNameAndPath.release(_stmt);
        }
      }
    });
  }

  @Override
  public Single<List<SmbEntry>> list() {
    final String _sql = "SELECT `smb`.`_id` AS `_id`, `smb`.`path` AS `path`, `smb`.`name` AS `name` FROM smb";
    final RoomSQLiteQuery _statement = RoomSQLiteQuery.acquire(_sql, 0);
    return RxRoom.createSingle(new Callable<List<SmbEntry>>() {
      @Override
      public List<SmbEntry> call() throws Exception {
        final Cursor _cursor = DBUtil.query(__db, _statement, false, null);
        try {
          final int _cursorIndexOfId = CursorUtil.getColumnIndexOrThrow(_cursor, "_id");
          final int _cursorIndexOfPath = CursorUtil.getColumnIndexOrThrow(_cursor, "path");
          final int _cursorIndexOfName = CursorUtil.getColumnIndexOrThrow(_cursor, "name");
          final List<SmbEntry> _result = new ArrayList<SmbEntry>(_cursor.getCount());
          while(_cursor.moveToNext()) {
            final SmbEntry _item;
            final String _tmpPath;
            _tmpPath = _cursor.getString(_cursorIndexOfPath);
            final String _tmpName;
            _tmpName = _cursor.getString(_cursorIndexOfName);
            _item = new SmbEntry(_tmpName,_tmpPath);
            _item._id = _cursor.getInt(_cursorIndexOfId);
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

  @Override
  public Single<SmbEntry> findByNameAndPath(final String name, final String path) {
    final String _sql = "SELECT `smb`.`_id` AS `_id`, `smb`.`path` AS `path`, `smb`.`name` AS `name` FROM smb WHERE name = ? AND path = ?";
    final RoomSQLiteQuery _statement = RoomSQLiteQuery.acquire(_sql, 2);
    int _argIndex = 1;
    if (name == null) {
      _statement.bindNull(_argIndex);
    } else {
      _statement.bindString(_argIndex, name);
    }
    _argIndex = 2;
    if (path == null) {
      _statement.bindNull(_argIndex);
    } else {
      _statement.bindString(_argIndex, path);
    }
    return RxRoom.createSingle(new Callable<SmbEntry>() {
      @Override
      public SmbEntry call() throws Exception {
        final Cursor _cursor = DBUtil.query(__db, _statement, false, null);
        try {
          final int _cursorIndexOfId = CursorUtil.getColumnIndexOrThrow(_cursor, "_id");
          final int _cursorIndexOfPath = CursorUtil.getColumnIndexOrThrow(_cursor, "path");
          final int _cursorIndexOfName = CursorUtil.getColumnIndexOrThrow(_cursor, "name");
          final SmbEntry _result;
          if(_cursor.moveToFirst()) {
            final String _tmpPath;
            _tmpPath = _cursor.getString(_cursorIndexOfPath);
            final String _tmpName;
            _tmpName = _cursor.getString(_cursorIndexOfName);
            _result = new SmbEntry(_tmpName,_tmpPath);
            _result._id = _cursor.getInt(_cursorIndexOfId);
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
}
